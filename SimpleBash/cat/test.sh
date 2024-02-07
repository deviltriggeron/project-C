#!/bin/sh
total_tests=0
success_tests=0
failed_tests=0

flags=(-b -e -n -s -t)
files=(test/t.txt test/tr.txt test/txt.txt)

for files in "${files[@]}"; do
    output_nf=$(./cat "$files")
    original_output_nf=$(cat "$files")
    total_tests=$((total_tests + 1))
    if [ "$output_nf" = "$original_output_nf" ]; then
        echo "Test passed: cat $files"
        success_tests=$((success_tests + 1))
    else
        echo "Test failed: cat $files"
        echo "Expected output:"
        echo "$original_output"
        echo "Actual output:"
        echo "$output"
        failed_tests=$((failed_tests + 1))
    fi
    for flags in "${flags[@]}"; do
        total_tests=$((total_tests + 1))
        output=$(./cat "$flags" "$files")
        original_output=$(cat "$flags" "$files")
        if [ "$output" = "$original_output" ]; then
            echo "Test passed: cat $flags $files"
            success_tests=$((success_tests + 1))
        else
            echo "Test failed: cat $flags $files"
            echo "Expected output:"
            echo "$original_output"
            echo "Actual output:"
            echo "$output"
            failed_tests=$((failed_tests + 1))
        fi
        
    done
done

echo "Total tests: $total_tests"
echo "Success tests: $success_tests"
echo "Failed tests: $failed_tests"
