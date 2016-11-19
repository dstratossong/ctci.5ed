#!/bin/bash

#
#	Author:	Arshan Alam
#	
#	Test Suite for testing problem CTCI Edition 6 #1.2 Check Permutation
#

TEST_DIR=$(cd $(dirname "$0") && pwd)
EXEC_FILE_NAME="URLify"
EXEC_FILE="$TEST_DIR/../$EXEC_FILE_NAME"
INPUT_FILES=($(ls *.in))
OUTPUT_FILES=($(ls *.out))
NUM_TEST=${#INPUT_FILES[@]}

for i in $(seq 0 $(($NUM_TEST-1))); do
	CUR_IN=$TEST_DIR/${INPUT_FILES[$i]}
	CUR_OUT=$TEST_DIR/${OUTPUT_FILES[$i]}
	EXEC_VAL=$($EXEC_FILE < $CUR_IN)
	OUTPUT_VAL=$(cat $CUR_OUT)
	if [ $EXEC_VAL != $OUTPUT_VAL ]; then
		echo "Test Failed: ${INPUT_FILES[$i]} | GOT $EXEC_VAL | EXPECTED $OUTPUT_VAL"
	fi
done
