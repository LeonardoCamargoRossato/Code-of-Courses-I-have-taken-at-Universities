program matrizesf90


implicit none
real:: esc
integer :: i, j

REAL :: A(3,3) = RESHAPE((/2.0,4.0,3.0,2.0,4.0,3.0,2.0,4.0,3.0/),(/3,3/))
REAL :: B(3,3) = RESHAPE((/2.0,1.0,1.0,3.0,2.0,2.0,4.0,3.0,3.0/),(/3,3/))
REAL :: C(3,3)
REAL :: D(3,3)
REAL :: E(3,3) 

Write(*,*)'Matriz [A]:'
do i=1,3
	Write(*,*) (a(i,j),j=1,3)
end do

Write(*,*)
Write(*,*)'Matriz [B]'
do i=1,3
	Write(*,*) (b(i,j),j=1,3)
end do


Write(*,*)
Write(*,*)'Matriz [C] = [A] + [B]'
C = A + B
do i=1,3
	Write(*,*) (c(i,j),j=1,3)
end do

Write(*,*) 
Write(*,*)'Matriz [A] x Escalar'
Write(*,*)'Para isso, digite o valor do Escalar: '
Read(*,*)esc

Write(*,*) 
print*,'Escalar:',esc

Write(*,*) 
E = esc*A
do i=1,3
	Write(*,*) (e(i,j),j=1,3)
end do

Write(*,*) 
Write(*,*)'Matriz [D] = [A] x [B]'
D = MATMUL(A,B)
do i=1,3
	Write(*,*) (d(i,j),j=1,3)
end do

Write(*,*)
Write(*,*)'Matriz [A] Transposta'
do i=1,3
	Write(*,*) (a(j,i),j=1,3)
end do

Write(*,*) 


end program 
