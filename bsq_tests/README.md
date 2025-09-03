# BSQ parser test suite

This folder contains a set of test files designed to exercise the parser (`ft_read_info`, `ft_read_map`, `ft_valid_map`) of the BSQ project.
Each file name encodes roughly the case; below is a short description and the *expected* outcome according to the Piscine BSQ specification.

Format: first line = header (rows + empty + obstacle + full), subsequent lines = map rows.

**Legend**: VALID = should be accepted by the parser as a valid map; INVALID = parser should print `map error`.

## Tests
- **valid_minimal_1x1.txt** — VALID minimal 1x1 — **Expected: VALID**
- **valid_1x5.txt** — VALID single row, 5 cols — **Expected: VALID**
- **valid_3x3.txt** — VALID small 3x3 with obstacle — **Expected: VALID**
- **valid_example_9x28.txt** — VALID example from prompt (9 rows) — **Expected: VALID**
- **valid_leading_zeros_header.txt** — VALID header with leading zeros (009 -> 9 rows) — **Expected: VALID**
- **invalid_header_too_short.txt** — INVALID header too short (<4 chars) — **Expected: INVALID**
- **invalid_duplicate_chars.txt** — INVALID duplicate empty/obstacle — **Expected: INVALID**
- **invalid_nonprintable_header.bin** — INVALID non-printable byte in header (binary file) — **Expected: INVALID**
- **invalid_non_digit_rows.txt** — INVALID non-digit rows in header — **Expected: INVALID**
- **invalid_header_too_long.txt** — INVALID header longer than allowed (pos >= 63) — **Expected: INVALID**
- **invalid_bad_chars_in_map.txt** — INVALID map contains character 'z' not declared in header — **Expected: INVALID**
- **invalid_line_length_mismatch.txt** — INVALID one line length is different from first — **Expected: INVALID**
- **invalid_less_rows_than_header.txt** — INVALID fewer lines than declared in header (5 vs 4) — **Expected: INVALID**
- **invalid_more_rows_than_header.txt** — INVALID more lines than declared in header (3 vs 4) — **Expected: INVALID**
- **invalid_missing_final_newline.txt** — INVALID missing final newline at EOF (last line has no trailing '\n') — **Expected: INVALID**
- **invalid_crlf_header.txt** — INVALID header contains CR (\r) before newline; non-printable in header — **Expected: INVALID**
- **invalid_crlf_map_lines.txt** — INVALID CRLF in map lines (each line contains CR 13 which is not an allowed map char) — **Expected: INVALID**
- **invalid_blank_line_between_rows.txt** — INVALID blank empty line between rows — **Expected: INVALID**
- **large_1000x1000_valid.txt** — VALID large 1000x1000 all empty (stress) — **Expected: VALID**
- **large_2000x2000_valid.txt** — VALID large 2000x2000 all empty (stress) — **Expected: VALID**
- **stress_random_obstacles_1000x1000.txt** — VALID large with sparse obstacles (deterministic seed 42) — **Expected: VALID**
- **invalid_info_with_leading_space.txt** — INVALID header starts with a space -> ft_atoi will fail (non-digit in rows) — **Expected: INVALID**
- **invalid_header_missing_chars.txt** — INVALID header missing one of the three info chars (pos < 4) — **Expected: INVALID**
- **invalid_rows_zero.txt** — INVALID header declares 0 rows (rows must be > 0) — **Expected: INVALID**
- **valid_single_col_2000rows.txt** — VALID single-column map with 2000 rows (stress) — **Expected: VALID**
- **invalid_map_with_digit_char.txt** — INVALID map contains '1' characters which are not declared in header — **Expected: INVALID**

Notes:
- Some files intentionally test edge behaviours (CRLF, missing final newline, non-printable characters in header, header longer than allowed by INFO_BUFFER_SIZE, etc.).
- The large files (large_1000x1000_valid.txt and large_2000x2000_valid.txt) are useful to test memory/IO behaviour. They are moderately large (≈1 MB and ≈4 MB respectively).
- `stress_random_obstacles_1000x1000.txt` is deterministic (seeded) so results should be reproducible.
- Files with `bin` or `wb` content (nonprintable header) are created as binary and may show up as .bin files.

How to run with your compiled bsq binary (example):
```
gcc -Wall -Wextra -Werror -I. *.c -o bsq
./bsq bsq_tests/valid_example_9x28.txt
./bsq bsq_tests/invalid_bad_chars_in_map.txt
```
