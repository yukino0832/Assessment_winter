import torch
import numpy as np
import pandas as pd



X = torch.rand(5,3)
# print(X.shape)
# print(X.dtype)                     # 默认为float32
# print(X.device)
Y = torch.tensor([[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15]])
Y=Y.reshape(5,3)
add=torch.add(X,Y)
sub=torch.sub(X,Y)
mul=torch.mul(X,Y)                   # 点积
matmul=torch.matmul(X,Y.T)           # 矩阵相乘
div=torch.div(X,Y)
X=X.abs()                            # 返回参数的绝对值
X=torch.sqrt(X)                      # 分别开方
X=torch.neg(X)                       # 分别取负
mean=torch.mean(X)                   # 求平均值
max=X.max()                          # 取张量中的最大值
argmax=X.argmax()                    # 最大值的索引
sum=X.sum()                          # 求和
# dim是张量的维度，比如X的第0维是这一个矩阵，第一维是三个向量，第二维是15个标量
tensor = torch.arange(1., 9.)
array = tensor.numpy()               # numpy转为tensor
tensor_back = torch.from_numpy(array)# tensor转为numpy
device = torch.device("cuda" if torch.cuda.is_available else "cpu")
tensor_cpu = torch.rand(2,3)
if torch.cuda.is_available():
    tensor_gpu = tensor_cpu.to(device)# 放在cuda中
    tensor_back_cpu = tensor_gpu.cpu()# 放在cpu中

X_cat0 = torch.cat([X, X], dim=0)    # 拼接在0维
X_cat1 = torch.cat([X, X], dim=1)    # 拼接在1维

X_squeeze = X.squeeze()              # 压缩所以单维度
X_unsqueeze = X.unsqueeze(dim=1)     # 在dim维上解压
