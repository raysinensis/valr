#' Generate randomly placed intervals on a genome.
#' 
#' @param genome genome tbl
#' @param length length of intervals
#' @param n number of intervals to generate
#' @param seed seed RNG for reproducible intervals
#' 
#' @family single-set-ops
#' @seealso \url{http://bedtools.readthedocs.org/en/latest/content/tools/random.html}
#'
#' @examples
#' genome <- tibble::tribble(
#'   ~chrom,  ~size,
#'   "chr1",  10000000,
#'   "chr2",  50000000,
#'   "chr3",  60000000,
#'   "chrX",  5000000
#' ) 
#' 
#' # random intervals (unsorted)
#' bed_random(genome, seed = 10104)
#'
#' # 500 random intervals of length 500 
#' bed_random(genome, length = 500, n = 500, seed = 10104)
#' 
#' @export
bed_random <- function(genome, length = 1000, n = 1e6, seed = 0) {
  
  if(!all(genome$size > length))
    stop('`length` must be greater than all chrom sizes', call. = FALSE)
  
  out <- random_impl(genome, length, n, seed)
  out <- tibble::as_tibble(out)
  out  
}
