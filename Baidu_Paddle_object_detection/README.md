# Usage

#### 1.处理单张图片

```shell
python infer.py --dataset='pascalvoc' --nms_threshold=0.45 --model_dir='./data/ssd_mobilenet_v1_pascalvoc' --image_path='./data/data104.png'
```

#### 2.使用摄像头处理视频流（但是由于paddle的限制，不可使用）

`python inferrealtime.py`

##### 尝试曲线救国：

写个脚本循环调用吧，哈哈哈

- 测试一：循环调用2.inferwhile.py读取数据集图片进行处理，测试实时处理性能:

```shell
./2.while.sh   #注意修改数据集路径
```

- 测试二：循环读取相机视频流处理:

```shell
第一个终端：
$ python 1.camsave.py  #调用相机实时保存帧
第二个终端：
./2.realtime.sh  #使用脚本循环调用2.inferwhile.py读取1.camsave.py实时保存的本地图片，并处理显示
```