# -*- coding: utf-8 -*-
"""
Created on Thu Nov 30 15:19:33 2017

@author: Somezaki
"""
import argparse
import tensorflow as tf
import os
import numpy as np
import pandas as pd

FLAGS=None
def main(_):
    dirname = os.path.join(FLAGS.buckets, "oil.csv")                  # 拼接路径，系统自动选择正确的路径分隔符"/"或"\"
    reader=tf.TextLineReader(skip_header_lines=1)                     # 实例化一个reader，每次读取一行
    filename_queue=tf.train.string_input_producer([dirname])          # 创建一个供reader读取的队列
    key,value=reader.read(filename_queue)                             # 使reader从队列中读取一个文件
    record_defaults=[[''],['']]                                       # 指定分割后每个属性的类型
                                                                      # ['']字符型，[1]&[0]整型，[1.0]&[0.0]浮点型
    d1, d2= tf.decode_csv(value, record_defaults, ',')                # 对每一行进行解析，第三个参数默认为逗号
    init=tf.global_variables_initializer()
    with tf.Session() as sess:
        sess.run(init)
        coord = tf.train.Coordinator()
        threads = tf.train.start_queue_runners(sess=sess,coord=coord) # 重要!!! 这个函数是启动队列, 不加这句线程会一直阻塞
        a=[]
        b=[]
        for i in range(10):
            c,d=(sess.run([d1,d2]))
            a.append(c)
            b.append(d)
        coord.request_stop()
        coord.join(threads)
        
    train = pd.DataFrame({'date':a,'dcoilwtico':b})
    print(train)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()                               # 创建解析器对象ArgumentParser，可以添加参数
    parser.add_argument('--buckets', type=str, default='',           # 指定程序需要接受的命令参数
                        help='input data path')
    parser.add_argument('--checkpointDir', type=str, default='',     # 指定程序需要接受的命令参数
                        help='output model path')
    FLAGS, _ = parser.parse_known_args()                             # 解析命令行参数，运行后得到结构体FLAGS
    tf.app.run(main=main)                                            # 解析flag，然后执行main函数