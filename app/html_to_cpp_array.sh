out=src/include/camera_index.h
cat /dev/null > $out

first=1
for file in app/index_*.html; do
  buffer=$(brotli -c $file | od -An -t x1 -v -w12 | sed 's/^[[:space:]]*/0x/; s/[[:space:]]*$/,/; s/[[:space:]]/, 0x/g; s/^/    /' | tac | awk '/,$/ && !seen {sub(/,$/, "};"); seen=1} 1' | tac)
  if [ $first -eq 1 ]; then
    first=0
  else
    echo >> $out
  fi
  echo "#define $(basename $file .html)_html_br_len $(echo $buffer | wc -w)" >> $out
  echo "const unsigned char $(basename $file .html)_html_br[] = {" >> $out
  echo "$buffer" >> $out
done
