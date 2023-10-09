#!/bin/bash

./account > recovered_details.log

diff <(cut -d']' -f2 19920104_091532.log) <(cut -d']' -f2 recovered_details.log)

if [ $? -eq 0 ]; then
    echo "The bank details are equivalent (despite the date and time)"
    exit 0
else
    echo "The bank details are not equivalent"
    exit 1
fi

