chmod -R 755 html-data
chmod 711 .
# find . -type f \( -name "*.pdf" -o -name "*.tex" -o -name "*.csv" -o -name "*.S" -o -name "*.circ" \) -exec chmod o+rx {} \;
