cat /dev/null > camera_index.h

for file in *.html; do
  echo "Processing $file"

  buffer=$(gzip -c $file | od -An -t x1 -v -w12 | sed 's/^[[:space:]]*/0x/; s/[[:space:]]*$/,/; s/[[:space:]]/, 0x/g; s/^/    /' | tac | awk '/,$/ && !seen {sub(/,$/, "};"); seen=1} 1' | tac)

  echo "#define $(basename $file .html)_html_gz_len $(cat $buffer | wc -w)" >> camera_index.h
  echo "constexpr const char $(basename $file .html)_html_gz[] = {" >> camera_index.h
  echo "$buffer\n" >> camera_index.h
done
