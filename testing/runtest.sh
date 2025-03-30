#!/bin/bash

RESULTS="results"

mkdir -p differences
> differences/$RESULTS

for file in input_tests/*; do
    filename=$(basename "$file")
    diff_file="differences/$filename"

    input_script=""
    while IFS= read -r line || [[ -n $line ]]; do
        input_script+="$line"$'\n'   
    done < "$file"

    ed_output=$(echo -e "$input_script" | ed)
    fake_ed_output=$(echo -e "$input_script" | ../ed)

    echo -e "Input script:\n$input_script" > "$diff_file"
    echo -e "\ned output:\n$ed_output" >> "$diff_file"
    echo -e "\n./ed output:\n$fake_ed_output" >> "$diff_file"

    # Check if outputs match
    # This doesn't work because of the escape sequences
    if [ "$ed_output" == "$fake_ed_output" ]; then
        echo "$filename - passed" >> differences/$RESULTS
        rm "$diff_file"  # Remove file if no differences
    else
        echo "$filename - failed" >> differences/$RESULTS
    fi

done