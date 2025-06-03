#!/bin/bash

LIBFT_DIR="src/libft"
OUTFILE="functions.c"
HEADER="#include \"libft_master.h\"\n\nLibFunc libft_functions[] = {\n"
FOOTER="\n};\n"

declare -A descriptions=(
  ["ft_memset"]="Fills memory with a constant byte."
  ["ft_bzero"]="Zeroes out a block of memory."
  ["ft_memcpy"]="Copies memory area."
  ["ft_memmove"]="Moves memory area handling overlap."
  ["ft_memchr"]="Searches for a byte in memory."
  ["ft_memcmp"]="Compares memory areas."
  ["ft_strlen"]="Returns the length of a string."
  # Add the rest of your function descriptions here
)

echo -e "$HEADER" > "$OUTFILE"

for file in "$LIBFT_DIR"/ft_*.c; do
  func_name=$(basename "$file" .c)
  description="${descriptions[$func_name]:-No description provided.}"

  # Skip the first 12 lines (42 header) and escape quotes and backslashes, wrap lines in quotes with \n
  impl=$(tail -n +13 "$file" | sed 's/\\/\\\\/g; s/"/\\"/g; s/^/"/; s/$/\\n"/')


  echo -e "\t{\n\t\t\"$func_name\"," >> "$OUTFILE"
  echo -e "\t\t\"$description\"," >> "$OUTFILE"
  echo -e "\t\t$impl" >> "$OUTFILE"
  echo -e "\t}," >> "$OUTFILE"
done

echo -e "$FOOTER" >> "$OUTFILE"
echo "Generated $OUTFILE with $(ls $LIBFT_DIR/ft_*.c | wc -l) functions."
