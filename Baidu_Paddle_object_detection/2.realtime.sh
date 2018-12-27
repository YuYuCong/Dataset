#!/bin/bash
while :
do
    python 2.inferwhile.py --dataset=pascalvoc --nms_threshold=0.45 --model_dir=./data/ssd_mobilenet_v1_pascalvoc --image_path='./frame.jpg'
    sleep 0 
done
