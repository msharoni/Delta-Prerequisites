mov ebx, eax          
and ebx, 0x000000FF
shl ebx, 24

mov ecx, eax
and ecx, 0x0000FF00
shl ecx, 8 

mov edx, eax
and edx, 0x00FF0000
shr edx, 8  
          
and eax, 0xFF000000
shr eax, 24

or eax, ebx
or eax, ecx
or eax, edx
