program matrizesf90


implicit none
real:: esc,esc2
integer :: i, j,i2,j2

!Definição dos Valores das Matrizes
REAL :: A3(3,3) = RESHAPE((/2.0,4.0,3.0,2.0,4.0,3.0,2.0,4.0,3.0/),(/3,3/))
REAL :: B3(3,3) = RESHAPE((/2.0,1.0,1.0,3.0,2.0,2.0,4.0,3.0,3.0/),(/3,3/))
REAL :: A2(2,2) = RESHAPE((/2.0,4.0,3.0,2.0/),(/2,2/))
REAL :: B2(2,2) = RESHAPE((/2.0,1.0,1.0,3.0/),(/2,2/))

REAL :: C3(3,3) !Soma de Matrizes
REAL :: D3(3,3) !Multiplicação de Matrizes
REAL :: E3(3,3) !Multiplicação por um Escalar

REAL :: C2(2,2) !Soma de Matrizes
REAL :: D2(2,2) !Multiplicação de Matrizes
REAL :: E2(2,2) !Multiplicação por um Escalar

Write(*,*)'Matriz [A3]:'
do i=1,3
	Write(*,*) (A3(i,j),j=1,3)
end do

Write(*,*)
Write(*,*)'Matriz [B3]'
do i=1,3
	Write(*,*) (B3(i,j),j=1,3)
end do


Write(*,*)
Write(*,*)'Matriz [C3] = [A3] + [B3]'
C3 = A3 + B3
do i=1,3
	Write(*,*) (C3(i,j),j=1,3)
end do

Write(*,*) 
Write(*,*)'Matriz [A3] x Escalar'
Write(*,*)'Para isso, digite o valor do Escalar: '
Read(*,*)esc

Write(*,*) 
print*,'Escalar:',esc

Write(*,*) 
E3 = esc*A3
do i=1,3
	Write(*,*) (E3(i,j),j=1,3)
end do

Write(*,*) 
Write(*,*)'Matriz [D3] = [A3] x [B3]'
D3 = MATMUL(A3,B3)
do i=1,3
	Write(*,*) (D3(i,j),j=1,3)
end do

Write(*,*)
Write(*,*)'Matriz [A3] Transposta'
do i=1,3
	Write(*,*) (A3(j,i),j=1,3)
end do

!##########################################################
Write(*,*)
Write(*,*) '----------------------------------------------'
Write(*,*)
!##########################################################

Write(*,*)'Matriz [A2]:'
do i2=1,2
	Write(*,*) (A2(i2,j2),j2=1,2)
end do

Write(*,*)
Write(*,*)'Matriz [B2]'
do i2=1,2
	Write(*,*) (B2(i2,j2),j=1,2)
end do


Write(*,*)
Write(*,*)'Matriz [C2] = [A2] + [B2]'
C2 = A2 + B2
do i2=1,2
	Write(*,*) (C3(i2,j2),j2=1,2)
end do

Write(*,*) 
Write(*,*)'Matriz [A2] x Escalar'
Write(*,*)'Para isso, digite o valor do Escalar: '
Read(*,*)esc2

Write(*,*) 
print*,'Escalar:',esc2

Write(*,*) 
E2 = esc2*A2
do i2=1,2
	Write(*,*) (E2(i2,j2),j2=1,2)
end do

Write(*,*) 
Write(*,*)'Matriz [D2] = [A2] x [B2]'
D2 = MATMUL(A2,B2)
do i2=1,2
	Write(*,*) (D2(i2,j2),j2=1,2)
end do

Write(*,*)
Write(*,*)'Matriz [A2] Transposta'
do i2=1,2
	Write(*,*) (A2(j2,i2),j2=1,2)
end do

end program 
