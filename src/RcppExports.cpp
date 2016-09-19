// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/valr.h"
#include <dplyr.h>
#include <Rcpp.h>

using namespace Rcpp;

// absdist_impl
DataFrame absdist_impl(GroupedDataFrame x, GroupedDataFrame y);
RcppExport SEXP valr_absdist_impl(SEXP xSEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< GroupedDataFrame >::type x(xSEXP);
    Rcpp::traits::input_parameter< GroupedDataFrame >::type y(ySEXP);
    rcpp_result_gen = Rcpp::wrap(absdist_impl(x, y));
    return rcpp_result_gen;
END_RCPP
}
// closest_impl
DataFrame closest_impl(GroupedDataFrame x, GroupedDataFrame y, const std::string& suffix_x, const std::string& suffix_y);
RcppExport SEXP valr_closest_impl(SEXP xSEXP, SEXP ySEXP, SEXP suffix_xSEXP, SEXP suffix_ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< GroupedDataFrame >::type x(xSEXP);
    Rcpp::traits::input_parameter< GroupedDataFrame >::type y(ySEXP);
    Rcpp::traits::input_parameter< const std::string& >::type suffix_x(suffix_xSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type suffix_y(suffix_ySEXP);
    rcpp_result_gen = Rcpp::wrap(closest_impl(x, y, suffix_x, suffix_y));
    return rcpp_result_gen;
END_RCPP
}
// complement_impl
DataFrame complement_impl(GroupedDataFrame gdf, DataFrame genome);
RcppExport SEXP valr_complement_impl(SEXP gdfSEXP, SEXP genomeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< GroupedDataFrame >::type gdf(gdfSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type genome(genomeSEXP);
    rcpp_result_gen = Rcpp::wrap(complement_impl(gdf, genome));
    return rcpp_result_gen;
END_RCPP
}
// intersect_impl
DataFrame intersect_impl(GroupedDataFrame x, GroupedDataFrame y, const std::string& suffix_x, const std::string& suffix_y);
RcppExport SEXP valr_intersect_impl(SEXP xSEXP, SEXP ySEXP, SEXP suffix_xSEXP, SEXP suffix_ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< GroupedDataFrame >::type x(xSEXP);
    Rcpp::traits::input_parameter< GroupedDataFrame >::type y(ySEXP);
    Rcpp::traits::input_parameter< const std::string& >::type suffix_x(suffix_xSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type suffix_y(suffix_ySEXP);
    rcpp_result_gen = Rcpp::wrap(intersect_impl(x, y, suffix_x, suffix_y));
    return rcpp_result_gen;
END_RCPP
}
// merge_impl
DataFrame merge_impl(GroupedDataFrame gdf, int max_dist);
RcppExport SEXP valr_merge_impl(SEXP gdfSEXP, SEXP max_distSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< GroupedDataFrame >::type gdf(gdfSEXP);
    Rcpp::traits::input_parameter< int >::type max_dist(max_distSEXP);
    rcpp_result_gen = Rcpp::wrap(merge_impl(gdf, max_dist));
    return rcpp_result_gen;
END_RCPP
}
// random_impl
DataFrame random_impl(DataFrame genome, int length, int n, int seed);
RcppExport SEXP valr_random_impl(SEXP genomeSEXP, SEXP lengthSEXP, SEXP nSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DataFrame >::type genome(genomeSEXP);
    Rcpp::traits::input_parameter< int >::type length(lengthSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(random_impl(genome, length, n, seed));
    return rcpp_result_gen;
END_RCPP
}
// reldist_impl
DataFrame reldist_impl(GroupedDataFrame x, GroupedDataFrame y);
RcppExport SEXP valr_reldist_impl(SEXP xSEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< GroupedDataFrame >::type x(xSEXP);
    Rcpp::traits::input_parameter< GroupedDataFrame >::type y(ySEXP);
    rcpp_result_gen = Rcpp::wrap(reldist_impl(x, y));
    return rcpp_result_gen;
END_RCPP
}
// shuffle_impl
DataFrame shuffle_impl(DataFrame df, DataFrame incl, bool within, int max_tries, int seed);
RcppExport SEXP valr_shuffle_impl(SEXP dfSEXP, SEXP inclSEXP, SEXP withinSEXP, SEXP max_triesSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DataFrame >::type df(dfSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type incl(inclSEXP);
    Rcpp::traits::input_parameter< bool >::type within(withinSEXP);
    Rcpp::traits::input_parameter< int >::type max_tries(max_triesSEXP);
    Rcpp::traits::input_parameter< int >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(shuffle_impl(df, incl, within, max_tries, seed));
    return rcpp_result_gen;
END_RCPP
}
// subtract_impl
DataFrame subtract_impl(GroupedDataFrame gdf_x, GroupedDataFrame gdf_y);
RcppExport SEXP valr_subtract_impl(SEXP gdf_xSEXP, SEXP gdf_ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< GroupedDataFrame >::type gdf_x(gdf_xSEXP);
    Rcpp::traits::input_parameter< GroupedDataFrame >::type gdf_y(gdf_ySEXP);
    rcpp_result_gen = Rcpp::wrap(subtract_impl(gdf_x, gdf_y));
    return rcpp_result_gen;
END_RCPP
}
