#!/bin/bash

# AWK Scripting Examples

# Create data file if it doesn't exist
if [ ! -f data.txt ]; then
cat << EOF > data.txt
101 Alice HR 50000
102 Bob IT 60000
103 Charlie IT 75000
104 David Sales 45000
EOF
fi

echo "--- All records ---"
awk '{print $0}' data.txt

echo -e "\n--- Name and Salary ---"
awk '{print $2, $4}' data.txt

echo -e "\n--- IT Department Employees ---"
awk '$3 == "IT" {print $2}' data.txt

echo -e "\n--- Total Salary Expenditure ---"
awk '{sum += $4} END {print "Total: " sum}' data.txt

echo -e "\n--- High earners (>50000) ---"
awk '$4 > 50000 {print $2, $4}' data.txt
