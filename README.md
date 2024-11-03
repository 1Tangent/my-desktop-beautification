# 桌面美化教程

更多可以看[以下网页](https://www.pling.com)

## 1. 修改主题

这里使用whitesur主题（确实这款最好看）

```bash
cd Whitesur-gtk-theme
sudo apt-get install gnome-tweaks
./install.sh # 更详细的使用说明参考它里面的README
gnome-tweaks # 修改背景和主题建议在tweaks中选择
```

修改主题可以直接看他界面提示即可

## 2. 修改图标

这里也使用whitesur的主题图标

```bash
cd Whitesur-gtk-theme
sudo apt-get install gnome-tweaks
./install.sh # 更详细的使用说明参考它里面的README
gnome-tweaks # 修改图标建议在tweaks中选择
```

修改图标可以直接看他界面提示即可

## 3. 修改grub

```bash
sudo mkdir /boot/grub/themes
sudo cp -r my_grub /boot/grub/themes
sudo gedit /etc/default/grub
# 在文件中添加以下内容  GRUB_THEME="/boot/grub/themes/my_grub/theme.txt"
```
grub定制：背景方面，可以直接修改background.png为你自己的图片；选择界面，可以看theme.txt里面的selected_item_color进行修改，选中的图像信息可以直接参考my_pic.cpp里面的实现进行自主定制

## 4. 修改开机logo

先根据他README里面修改logo图片（建议使用Windows的画图），然后进行下述配置

```bash
sudo cp -r my_logo /usr/share/plymouth/themes
sudo update-alternatives --install /usr/share/plymouth/themes/default.plymouth default.plymouth /usr/share/plymouth/themes/my_logo/logo-mac-style.plymouth 110
sudo update-initramfs -u -k all
```

## 5. 修改开机背景

```bash
cd change-gdm-background
sudo chmod a+x ./change-gdm-background
sudo ./change-gdm-background /your/background/path
```

## 6. 添加桌面插件

```bash
sudo apt-get install conky-all lua5.3
cd ~/.config
mkdir conky && cd conky
cp -r my_desktop_plug .
cd my_desktop_plug
# 把这个文件夹中的字体全部下载
sudo fc-cache -v -f
```
打开scripts中的weather-v2.0.sh脚本，根据[这个链接](https://openweathermap.org)中的地址信息来修改city_id

然后根据res/ref_my_pic.png的尺寸来修改成自己想要添加的图片

自启动：
```bash
sudo cp my_autostart.sh /efi/init.d && cd /efi/init.d
sudo chmod 775 my_autostart.sh
sudo update-rc.d my_autostart.sh defaults 90
```

重启即可
如果上述自启动不好使，则需每次开机执行如下命令
```bash
cd .config/conky/my_desktop_plug
sh start.sh
```
即可以每次启动桌面插件

## 7. 终端美化

终端使用zsh，需注意在编译ros package后source的时候要source devel/setup.zsh

```bash
sudo apt-get install zsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```
更多终端美化建议去github搜索oh-my-zsh# my-desktop-beautification
# my-desktop-beautification
