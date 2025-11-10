# SimpleScalar Usage — Running Experiments

## Compile C Programs (PISA Target)

$IDIR/bin/sslittle-na-sstrix-gcc -O2 -o <output> <program>.c

Example:
$IDIR/bin/sslittle-na-sstrix-gcc -O2 -o 1 1.c


## Analyze Branch Predictors

$IDIR/simplesim-3.0/sim-outorder -bpred <predictor> <program>

Examples:
$IDIR/simplesim-3.0/sim-outorder -bpred 2lev 1
$IDIR/simplesim-3.0/sim-outorder -bpred bimod 1
$IDIR/simplesim-3.0/sim-outorder -bpred comb 1


## Supported Predictors
taken  
nottaken  
bimod  
2lev  
comb
