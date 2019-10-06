import os
import shutil

path = os.path.dirname(os.path.realpath(__file__))

new_folder = next(os.walk(path))[0]

#r = root, d = directories, f = files
for r, d, f in os.walk(path):
        
        for file in f:
                
                if '.c' in file:

                        file_path = os.path.join(r, file)

                        shutil.copy(file_path, new_folder)
