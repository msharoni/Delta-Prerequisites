mov eax,0   ;eax = 0
add eax,1   ;eax = 1
add eax,2   ;eax = 3
add eax,3   ;eax = 6

;after this part of the code eax = 6

xor eax,eax ;eax = 0 because any number xor with itself is 0
mov ebx,eax ;ebx = eax = 0
dec ebx     ;ebx -= 1 -> ebx = 0XFFFFFFFF = -1