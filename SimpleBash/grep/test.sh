#!/bin/sh
total_tests=0
passed_tests=0
failed_tests=0

flag=(-e -i -v -c -l -n -s)
pattern=("t" "a" "line" "serenity")
file=(test/abc.txt test/t.txt test/tes.txt)

for file in "${file[@]}"; do
    for pattern in "${pattern[@]}"; do
        total_tests=$((total_tests + 1))
        output_nf=$(./s21_grep "$pattern" "$file")
        original_output_nf=$(grep "$pattern" "$file")
        if [ "$output_nf" = "$original_output_nf" ]; then
            echo "Test success: grep $pattern $file"
            success_tests=$((success_tests + 1))
        else
            echo "Test failed: grep $pattern $file"
            echo "Expected output:"
            echo "$original_output_nf"
            echo "Actual output:"
            echo "$output_nf"
            failed_tests=$((failed_tests + 1))
        fi
        for flag in "${flag[@]}"; do
            total_tests=$((total_tests + 1))
            output=$(./s21_grep "$flag" "$pattern" "$file")
            original_output=$(grep "$flag" "$pattern" "$file")
            if [ "$output" = "$original_output" ]; then
                echo "Test success: grep $flag $pattern $file"
                success_tests=$((success_tests + 1))
            else
                echo "Test failed: grep $flag $pattern $file"
                echo "Expected output:"
                echo "$original_output"
                echo "Actual output:"
                echo "$output"
                failed_tests=$((failed_tests + 1))
            fi
        done
    done
done

echo "Total tests: $total_tests"
echo "Success tests: $success_tests"
echo "Failed tests: $failed_tests"

