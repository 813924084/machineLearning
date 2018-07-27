# -*- coding: utf-8 -*-
"""
Created on Sat Dec  2 11:30:21 2017

@author: Somezaki
"""

import argparse
import tensorflow as tf
import os
import numpy as np
import pandas as pd

FLAGS=None
def main(_):
    dirname = os.path.join(FLAGS.buckets, "test.csv")                
    tf.gfile.Copy(dirname,'./test.csv')
    test = pd.read_csv('test.csv')
    test.to_csv('save_test.csv',index=False) 
    new_save_dir = os.path.join(FLAGS.buckets, "save_test.csv")
    tf.gfile.Copy('./save_test.csv',new_save_dir)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()                               
    parser.add_argument('--buckets', type=str, default='',         
                        help='input data path')
    parser.add_argument('--checkpointDir', type=str, default='',   
                        help='output model path')
    FLAGS, _ = parser.parse_known_args()                            
    tf.app.run(main=main)                                            