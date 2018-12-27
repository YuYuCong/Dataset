#!/bin/bash
int=1
while [ $int -le 100 ]
imgname='../data/data_classroomD9D405_2018.10.22_10:05/data001.png'
do
    imgnum=$int
    imgnum=`echo $imgnum|awk '{printf("%03d\n",$0)}'`
    imgname="${imgname%/data*}/data$imgnum.png"
    python 2.inferwhile.py --dataset=pascalvoc --nms_threshold=0.45 --model_dir=./data/ssd_mobilenet_v1_pascalvoc --image_path=$imgname
    let int++
    sleep 0 
done
