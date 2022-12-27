# 1. Only valid for directed graph and is used to detect the negative edge cycle
# 2. then edges can be of any order
<hr></hr>

# 3. for undiredted we need to create edges directed towards each other

# 4. for n vertex we need to do n-1 iteration 
because - the edges will be going to present at an order so to get the distance of the previous edges inorder to find out the distance of current vertex we need to do n-1 iteration (1-n-1)

# How to detect negative edge cycle 
if after n-1 iteration , if we do nth iteration and still the distance is decrasing it means that there is negative edges cycle