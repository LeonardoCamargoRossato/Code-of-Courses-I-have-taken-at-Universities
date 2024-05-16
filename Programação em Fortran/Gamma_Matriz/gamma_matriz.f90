program gamma_matrizf90

implicit none
real :: esc
integer :: i,j

Complex :: const(4,4) =RESHAPE((/(0,1),(0,0),(0,0),(0,0),&
(0,0),(0,1),(0,0),(0,0),&
(0,0),(0,0),(0,1),(0,0),&
(0,0),(0,0),(0,0),(0,1)/),(/4,4/))

Complex :: gamma0(4,4) =RESHAPE((/(1,0),(0,0),(0,0),(0,0),&
(0,0),(1,0),(0,0),(0,0),&
(0,0),(0,0),(-1,0),(0,0),&
(0,0),(0,0),(0,0),(-1,0)/),(/4,4/))

Complex :: gamma1(4,4) =RESHAPE((/(0,0),(0,0),(0,0),(1,0),&
(0,0),(0,0),(1,0),(0,0),&
(0,0),(-1,0),(0,0),(0,0),&
(-1,0),(0,0),(0,0),(0,0)/),(/4,4/))

Complex :: gamma2(4,4) =RESHAPE((/(0,0),(0,0),(0,0),(0,-1),&
(0,0),(0,0),(0,1),(0,0),&
(0,0),(0,1),(0,0),(0,0),&
(0,-1),(0,0),(0,0),(0,0)/),(/4,4/))

Complex :: gamma3(4,4) =RESHAPE((/(0,0),(0,0),(1,0),(0,0),&
(0,0),(0,0),(0,0),(-1,0),&
(-1,0),(0,0),(0,0),(0,0),&
(0,0),(1,0),(0,0),(0,0)/),(/4,4/))

Complex :: D(4,4)
Complex :: E(4,4)
Complex :: F(4,4)
Complex :: gamma5(4,4)
Complex :: GG(4,4)

Write(*,*)'Matriz Gamma0'
do i=1,4
Write(*,*) (gamma0(i,j),j=1,4)
end do

D = MATMUL(gamma0,gamma1)
E = MATMUL(gamma2,gamma3)
F = MATMUL(D,E)
gamma5 = MATMUL(const,F)

Write(*,*)
Write(*,*)'Matriz gamma5 = I*(gamma0 * gamma1 * gamma2 * gamma3)'

do i=1,4
Write(*,*) (gamma5(i,j) , j=1,4)
end do


! SOMA DAS MATRIZES GAMMA1 + GAMMA5

GG(4,4) = gamma1(4,4) !+ gamma0(4,4) 

Write(*,*)
Write(*,*)'Matriz GG - Soma Gamma0 + Gamma5'

do i=1,4
Write(*,*) (GG(i,j), j=1,4)
end do



end program
