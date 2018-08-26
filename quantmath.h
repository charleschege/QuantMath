/* Generated with cbindgen:0.6.2 */

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Controls what to do if we are reading or writing a recursive structure
 * and we hit a node that is the same as the type we are controlling.
 * ErrorIfMissing requires all subnodes to be supplied externally. Inline
 * requires all subnodes to be supplied inline. WriteOnce allows nodes to be
 * supplied either inline or externally. When writing, WriteOnce writes each
 * unique node once, the first time it is encounted, and thereafter does not
 * write them.
 */
enum QmDedupControl {
    QmErrorIfMissing,
    QmInline,
    QmWriteOnce,
};

/*
 * Compares two reports for equality. If they are equal, it returns a handle of type Empty, which
 * is not an error. If they are not equal, it returns a handle of type Error, where the error
 * message details the differences between the reports. This is normally used for testing.
 *
 * Both of the report handles passed into the function are freed by the function, so you must not
 * invoke free_handle on them. The tolerances are absolute, and specify the allowed differences:
 * tol_price is the allowed difference in the price -- for Monte-Carlo this must be larger than the
 * expected Monte-Carlo noise; tol_ccy_risk is the allowed difference in risks that are measured in
 * units of currency such as Vega or PV01 -- this is likely to be smaller than tol_price, as the same
 * Monte-Carlo paths are used for different bumped paths in risk calculations; tol_unit_risk is the
 * allowed difference to risks that are measured in non-dimensional units such as delta -- this does
 * not scale with the notional.
 *
 * The resulting handle must be freed with free_handle. In the event of error, the
 * resulting handle is of type error, and returns true for qm_is_error. You can
 * test for errors immediately after invoking this method, or you can simply use
 * the handle and propagate the error.
 */
uint64_t qm_assert_approx_eq_reports(uint64_t reports_freed,
                                     uint64_t expected_freed,
                                     double tol_price,
                                     double tol_ccy_risk,
                                     double tol_unit_risk);

/*
 * Calculates a set of reports on the given data. The pricer_factory specifies how
 * pricing is to be done; the instrument specifies what is to be priced; the fixing_table
 * and market_data specify the context for pricing, and the report generators specify what
 * is to be calculated.
 *
 * The results are returned as a handle containing reports. These can be viewed as JSON by
 * invoking qm_reports_as_json_string, or can be compared with other reports by invoking
 * qm_assert_approx_eq_reports, which will free the reports handle for you.
 *
 * Reports are not cloneable, and are generally consumed by functions that use them, except for
 * simple ones such as is_error or qm_reports_as_json_string. If you do not invoke a method such as
 * qm_assert_approx_eq_reports, you must manually free the reports using free_handle. If the reports
 * are badly formed, the method may return a handle of type error. You can
 * test for errors immediately after invoking this method, by calling qm_is_error, or you can simply use
 * the handle and propagate the error.
 */
uint64_t qm_calculate(uint64_t pricer_factory,
                      uint64_t instrument,
                      uint64_t fixing_table,
                      uint64_t market_data,
                      uint32_t number_of_report_generators,
                      const uint64_t *report_generators);

/*
 * Returns a clone of the given handle. The clone must also be eventually freed using qm_free_handle.
 * Any handle can be cloned except for one containing a set of reports. Cloning that would end up
 * with a handle representing an error. Error handles can also be cloned.
 */
uint64_t qm_clone(uint64_t handle);

/*
 * Creates a handle (an opaque 64bit unsigned int) that represents a currency. For example, it can
 * be passed into the instrument creation functions. The source is a UTF8-encoded filename referring
 * to a text file containing UTF8-encoded JSON. (UTF8 is the same as ASCII for the standard characters
 * 0..127.).
 *
 * The resulting handle must be freed with free_handle. In the event of error, the
 * resulting handle is of type error, and returns true for qm_is_error. You can
 * test for errors immediately after invoking this method, or you can simply use
 * the handle and propagate the error.
 */
uint64_t qm_currency_from_json_file(const char *source);

/*
 * Same as qm_currency_from_json_file, but taking inline text.
 */
uint64_t qm_currency_from_json_string(const char *source);

/*
 * Returns the error string associated with this handle. If the handle does not represent
 * an error, the call will give you an error message anyway, for using a handle of the
 * wrong type.
 *
 * The resulting string must be freed using qm_free_string
 */
char *qm_error_string(uint64_t handle);

/*
 * Loads a fixing table from a JSON UTF8 file.
 *
 * The resulting handle must be freed with free_handle. In the event of error, the
 * resulting handle is of type error, and returns true for qm_is_error. You can
 * test for errors immediately after invoking this method, or you can simply use
 * the handle and propagate the error.
 */
uint64_t qm_fixing_table_from_json_file(const char *source);

/*
 * Same as qm_fixing_table_from_json_file, but taking inline text.
 */
uint64_t qm_fixing_table_from_json_string(const char *source);

/*
 * Frees a handle that was created by most of the other methods in this interface. Handles ought to be
 * freed, or there is a memory leak. Handles must not be freed more than once -- trying to do so is
 * likely to result in a core dump.
 */
void qm_free_handle(uint64_t handle);

/*
 * Frees a string that was allocated by a method such as qm_error_string. Strings must
 * only be freed once.
 */
void qm_free_string(char *string);

/*
 * Loads an instrument from a JSON UTF8 file. Currencies and subinstruments can
 * be supplied inline or provided in arrays, according to the dedup parameters.
 *
 * The resulting handle must be freed with free_handle. In the event of error, the
 * resulting handle is of type error, and returns true for qm_is_error. You can
 * test for errors immediately after invoking this method, or you can simply use
 * the handle and propagate the error.
 */
uint64_t qm_instrument_from_json_file(const char *source,
                                      enum QmDedupControl dedup_ccy,
                                      uint32_t number_of_currencies,
                                      const uint64_t *currencies,
                                      enum QmDedupControl dedup_instr,
                                      uint32_t number_of_instruments,
                                      const uint64_t *instruments);

/*
 * Same as qm_instrument_from_json_file, but taking inline text.
 */
uint64_t qm_instrument_from_json_string(const char *source,
                                        enum QmDedupControl dedup_ccy,
                                        uint32_t number_of_currencies,
                                        const uint64_t *currencies,
                                        enum QmDedupControl dedup_instr,
                                        uint32_t number_of_instruments,
                                        const uint64_t *instruments);

/*
 * Tests whether a handle represents an error. If it does, you should normally invoke
 * qm_error_string to find out what the error is.
 */
bool qm_is_error(uint64_t handle);

/*
 * Loads a market data collection from a JSON UTF8 file.
 *
 * The resulting handle must be freed with free_handle. In the event of error, the
 * resulting handle is of type error, and returns true for qm_is_error. You can
 * test for errors immediately after invoking this method, or you can simply use
 * the handle and propagate the error.
 */
uint64_t qm_market_data_from_json_file(const char *source);

/*
 * Same as qm_market_data_from_json_file, but taking inline text.
 */
uint64_t qm_market_data_from_json_string(const char *source);

/*
 * Loads a pricer factory from a JSON UTF8 file. Pricer factories specify how pricing is to be done. For
 * example, a Monte-Carlo pricer factory specifies the number of paths, and the stochastic model to be
 * used.
 *
 * The resulting handle must be freed with free_handle. In the event of error, the
 * resulting handle is of type error, and returns true for qm_is_error. You can
 * test for errors immediately after invoking this method, or you can simply use
 * the handle and propagate the error.
 */
uint64_t qm_pricer_factory_from_json_file(const char *source);

/*
 * Same as qm_pricer_factory_from_json_file, but taking inline text.
 */
uint64_t qm_pricer_factory_from_json_string(const char *source);

/*
 * Loads a report generator from a JSON UTF8 file. Report generators are supplied to the
 * qm_calculate function, and specify which reports are to be calculated, such as DeltaGamma for
 * all assets, etc.
 *
 * The resulting handle must be freed with free_handle. In the event of error, the
 * resulting handle is of type error, and returns true for qm_is_error. You can
 * test for errors immediately after invoking this method, or you can simply use
 * the handle and propagate the error.
 */
uint64_t qm_report_generator_from_json_file(const char *source);

/*
 * Same as qm_report_generator_from_json_file, but taking inline text.
 */
uint64_t qm_report_generator_from_json_string(const char *source);

/*
 * Converts a handle representing a set of reports into a string. The string must
 * be freed using qm_free_string. The handle is left unchanged and unfreed by this
 * call.
 *
 * If the handle is an error or does not contain a set of reports, an error message
 * is returned instead. The string must be freed using qm_free_string whether it is
 * an error or not.
 */
char *qm_reports_as_json_string(uint64_t handle);

/*
 * Loads a set of reports from a JSON UTF8 file. Reports are normally generated by a qm_calculate,
 * so the only reason you would load them from a file is for testing or for distribution.
 *
 * Reports are not cloneable, and are generally consumed by functions that use them, except for
 * simple ones such as is_error or qm_reports_as_json_string. If you do not invoke a method such as
 * qm_assert_approx_eq_reports, you must manually free the reports using free_handle. If the reports
 * are badly formed, the method may return a handle of type error. You can
 * test for errors immediately after invoking this method, by calling qm_is_error, or you can simply use
 * the handle and propagate the error.
 */
uint64_t qm_reports_from_json_file(const char *source);

/*
 * Same as qm_reports_from_json_file, but taking inline text.
 */
uint64_t qm_reports_from_json_string(const char *source);
