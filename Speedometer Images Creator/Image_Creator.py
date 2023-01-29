from PIL import Image

folder_path = "D:\\Documents\\Uni Files\\IA\\Full Blue Racing\\Nextion-Images\\Speedometer Images Creator\\"
image_size = (173,175)

def combine_images(angle,name):
    arrow_path = folder_path+"Rotatable Arrow.png"
    background_path = folder_path+"speedometer image with numers and writing.bmp"

    arrow_image = Image.open(arrow_path)
    background_image = Image.open(background_path)

    arrow_image = arrow_image.convert("RGBA")
    background_image = background_image.convert("RGBA")

    arrow_image = arrow_image.rotate(angle)
    arrow_image.save("temp.png",format="png")
    arrow_image = arrow_image.convert("RGBA")
    background_image = background_image.convert("RGBA")

    

    width = (background_image.width - arrow_image.width) // 2
    height = 0

    background_image.paste(arrow_image, (width, height), arrow_image)
    background_image = background_image.resize(image_size)
    background_image.save("./Image Destination/"+name+".bmp", format="bmp")


def create_images(start_angle,stop_angle):
    for i in range(start_angle, stop_angle):
        combine_images(-i,"speedometer_image_"+str(i)+"_deg")

create_images(0,271)
