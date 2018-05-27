#!/usr/bin/env bash
PDF_SRC_DIRS=(`find .. -not -path '../.*' -name .pdfsrc`)
PDF_FILES=()
rm -rf gen_makefile
touch gen_makefile
for i in "${PDF_SRC_DIRS[@]}"; do
    OUTER_DIR=`dirname ${i}`
    for TEX_FILE in `ls ${i}/*.tex`; do
        git add ${TEX_FILE}
        BASE_NAME=`basename ${TEX_FILE:0:-4}`
        PDF_FILE="${OUTER_DIR}/${BASE_NAME}.pdf"
        PDF_FILES+=(${PDF_FILE})
    done
    git add ${OUTER_DIR}/*.c &>/dev/null
    git add ${OUTER_DIR}/*.h &>/dev/null
    echo "${PDF_FILE}: ${TEX_FILE}" >> gen_makefile
    printf "\tcd ${i} && pdflatex -interaction=nonstopmode -halt-on-error ${BASE_NAME}.tex && mv *.pdf ..\n\n" >> gen_makefile
done

echo ".PHONY: build" >> gen_makefile
echo "build: ${PDF_FILES[@]}" >> gen_makefile
