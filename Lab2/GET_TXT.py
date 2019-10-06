import os
import shutil

#path that this script is in
path = os.path.dirname(os.path.realpath(__file__))

#r = root, d = directories, f = files
for r, d, f in os.walk(path):
        
        for file in f:
                
                if '.c' in file:

                        #joins the root and file to make file path
                        file_path = os.path.join(r, file)

                        #copies the file to path
                        shutil.copy(file_path, path)

                        #makes new file path where copied file is
                        file_path = os.path.join(path, file)

                        #renames copied file from '.c' to '.txt'
                        new_file_path = file_path[:-2] + '.txt'
                        os.rename(file_path, new_file_path)
