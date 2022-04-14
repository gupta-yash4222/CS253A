#!/bin/bash

printFields() {
    awk -F',' '{print $1,$2,$3,$5,$6,$7,$10,$11}' $1 > $2
}

printHighestDegree() {
    awk -F',' '{ if($3 == "Bachelor'"'"'s") print $1}' $1 >> $2
}

printAverAdmissionRate() {

    IFS=$'\n'
    geoArr=($(awk -F',' 'NR>1 {print $6}' "$1" | awk '!a[$0]++' | awk '{print $0}'))

    echo "Geography: Average Admission Rate" >> $2

    for geo in "${geoArr[@]}"
    do
        :
        awk -F',' '
            BEGIN {rate=0; count=0}
            {
                if($6 == "'$(echo $geo)'") { rate+=$7; count++ }    
            }
            END {print "'$(echo $geo)'",rate/count}
        ' $1 >> $2
    done    
    
}

printTopMedEarning() {

    sort -k16 -n -t, -r $1 | awk -F',' 'NR<=5 {print $1}' >> $2

}



if [ $# != 2 ]
then 
    echo "Invalid number of arguments. Expected two"
    exit 1
fi

FILE1=$1
FILE2=$2

if [ ! -f "$FILE1" ]
then
    echo "First argument is not a valid file name. Enter a valid and readable file name."
    exit 1
fi

printFields ${FILE1} ${FILE2}

printHighestDegree ${FILE1} ${FILE2}

printAverAdmissionRate ${FILE1} ${FILE2}

printTopMedEarning ${FILE1} ${FILE2}
