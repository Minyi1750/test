from PIL import Image
from pylab import *

#打開文件，並灰度變換 且數組化。
im = array(Image.open('D:/test.png').convert('L'))

#对图像进行反相处理
im2 = 255 -im
im3 = (100.0/255) * im + 100
im4 = 255.0 * (im/255.0)**2

#从数组到图像
pil_im = Image.fromarray(uint8(im2))
pil_im_3 = Image.fromarray(uint8(im3))
pil_im_4 = Image.fromarray(uint8(im4))

#如何将数组变换为图像, 曰保存即可。
pil_im.save('D:/im2.jpg')
pil_im_3.save('D:/pil_im_3.jpg')
pil_im_4.save('D:/pil_im_4.jpg')

