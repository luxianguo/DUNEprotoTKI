which mkexe.sh


#####

mkdir -p output

mkexe.sh anaData -lstyle -I../style  -L../style || return 1

#make legend
./anaData ; 

#exit


for kPiZero in 0 
do 
    for kProton in 1
                   #0 1
    do
        for kTruth in 0
                      #0 1
        do
            ./anaData $kPiZero $kProton $kTruth >seeana${kPiZero}${kProton}${kTruth}.log 
        done
    done
done
