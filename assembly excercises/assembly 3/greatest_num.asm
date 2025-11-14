cmp eax, ebx     
jl  ebx_bigger 

jmp  eax_bigger

ebx_bigger:
    mov eax, ebx  

eax_bigger:
    cmp eax, ecx  
    jl  ecx_bigger
    jmp done

ecx_bigger:
    mov eax, ecx  ; num3 is bigger, move to EAX

done:
