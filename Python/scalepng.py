#! /usr/bin/env python
################################################################################
#     File Name : test.py
#     Created By : kuriko
#     Creation Date : [2017-09-22 14:57]
#     Last Modified : [2017-09-22 15:14]
#     Description : test
################################################################################

import numpy as np
import scipy.misc

scale = 10 

def main():
    """TODO: Docstring for main.
    :returns: TODO
    """
    im = scipy.misc.imread("test.png")
    nim = [[0 for j in range(len(im[0]) * scale)]
            for i in range(len(im) * scale)]
    for i in range(len(im)):
        for j in range(len(im[0])):
            for k in range(scale):
                for l in range(scale):
                    nim[i * scale + k][j * scale + l] = im[i][j]
    scipy.misc.imsave("233.png", nim)
    return

if __name__ == "__main__":
    main()
