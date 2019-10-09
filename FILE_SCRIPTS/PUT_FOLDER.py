import os
import shutil

#path that this script is in
path = os.path.dirname(os.path.realpath(__file__))

# r = root, d = directories, f = files
for r, d, f in os.walk(path):

    for file in f:

        if '.c' in file:
        
            #the file name with extension
            file_name = file

            #strips the '.c' extension and makes folder dir
            file = file[:-2]
            new_folder = os.path.join(r, file)

            #makes new folder with file name
            try:
                if not os.path.exists(new_folder):
                    print(new_folder)
                    os.makedirs(new_folder)
            except OSError:
                print('Error: Creating directory. ' + new_folder)

            #copies original .c file into folder
            shutil.copy(file_name, new_folder)
