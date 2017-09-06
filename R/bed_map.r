#' Calculate summaries from overlapping intervals.
#'
#' Used to apply functions like [min()] and [count()] to intersecting
#' intervals. Book-ended intervals are not reported by default, but can be
#' included by setting `min_overlap = 0`.
#'
#' @param x [tbl_interval()]
#' @param y  [tbl_interval()]
#' @param ... name-value pairs specifying colnames and expressions to apply
#' @param min_overlap minimum overlap for intervals.
#'
#' @template groups
#'
#' @return [tbl_interval()]
#'
#' @family multiple set operations
#'
#' @seealso
#' \url{http://bedtools.readthedocs.io/en/latest/content/tools/map.html}
#'
#' @examples
#' x <- trbl_interval(
#'   ~chrom, ~start, ~end,
#'   'chr1',      1,      100
#' )
#'
#' y <- trbl_interval(
#'   ~chrom, ~start, ~end, ~value,
#'   'chr1', 1,      20,   10,
#'   'chr1', 30,     50,   20,
#'   'chr1', 90,     120,  30
#' )
#'
#' bed_glyph(bed_map(x, y, value = sum(value)), label = 'value')
#'
#' x <- trbl_interval(
#'  ~chrom, ~start, ~end,
#'  'chr1', 100,    250,
#'  'chr2', 250,    500
#' )
#'
#' y <- trbl_interval(
#'  ~chrom, ~start, ~end, ~value,
#'  'chr1', 100,    250,  10,
#'  'chr1', 150,    250,  20,
#'  'chr2', 250,    500,  500
#' )
#'
#' # also mean, median, sd etc
#' bed_map(x, y, .sum = sum(value))
#'
#' bed_map(x, y, .min = min(value), .max = max(value))
#'
#' bed_map(x, y, .concat = concat(value))
#'
#' # create a list-col
#' bed_map(x, y, .values = list(value))
#'
#' # can also use `nth` family from dplyr
#' bed_map(x, y, .first = dplyr::first(value))
#'
#' bed_map(x, y, .last = dplyr::last(value))
#'
#' bed_map(x, y, .absmax = abs(max(value)))
#'
#' bed_map(x, y, .absmin = abs(min(value)))
#'
#' bed_map(x, y, .count = length(value))
#'
#' bed_map(x, y, .count_distinct = length(unique(value)))
#'
#' bed_map(x, y, .vals = values(value))
#'
#' bed_map(x, y, .vals.unique = values_unique(value))
#'
#' @export
bed_map <- function(x, y, ..., min_overlap = 1) {
  if (!is.tbl_interval(x)) x <- as.tbl_interval(x)
  if (!is.tbl_interval(y)) y <- as.tbl_interval(y)

  suffix <- list(x = ".x", y = ".y")
  x_nms <- str_c(names(x), suffix$x)
  x_nms <- x_nms[!x_nms %in% "chrom.x"]

  x <- group_by(x, chrom, add = TRUE)
  y <- group_by(y, chrom, add = TRUE)

  res <- intersect_impl(x, y, invert = TRUE, suffix_x = ".x", suffix_y = "")

  res_noint <- filter(res, is.na(.overlap))
  res_noint <- select(res_noint, chrom, ends_with('.x'))

  ## map supplied functions to each set of intervals
  res_int <- filter(res, !is.na(.overlap))
  res_int <- group_by(res_int, !!! syms(c("chrom", x_nms)))
  res_int <- summarize(res_int, !!! quos(...))
  res_int <- ungroup(res_int)

  res <- bind_rows(res_int, res_noint)
  res <- select(
    res, chrom,
    start = start.x,
    end = end.x, everything()
  )
  res <- bed_sort(res)

  res
}

#' @export
#'
#' @param .data data
#' @param sep separator character
#'
#' @rdname bed_map
concat <- function(.data, sep = ",") {
  paste0(.data, collapse = sep)
}

#' @export
#' @rdname bed_map
values_unique <- function(.data, sep = ",") {
  concat(unique(.data), sep = sep)
}

#' @export
#' @rdname bed_map
values <- function(.data, sep = ",") {
  concat(rle(.data)$values, sep = sep)
}
