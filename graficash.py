import numpy as np
from matplotlib import pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.animation import PillowWriter

m=100
beta=0.05
c=1
dx=1./m
dt=beta*dx/c
T_final=0.1
n=int(T_final/dt)+1

data = np.loadtxt("Data.dat")
grid = np.reshape(data, (n, m))

fig = plt.figure()
ax = plt.axes(xlim=(0, 1), ylim=(-0.05, 0.05))
plt.xlabel('Posicion[metros]')
plt.ylabel('U')
line, = ax.plot([], [], lw=3)

def init():
    line.set_data([], [])
    return line,

def animate(i):
    x = np.linspace(0, 1, m)
    y = 0.05*grid[i]
    t = (2/0.1)*i*dt
    fig.suptitle('Tiempo: %1.2f segundos' %t)
    line.set_data(x, y)
    return line,

anim = FuncAnimation(fig, animate, init_func=init,
                               frames=200, interval=20, blit=True,repeat=False)

writer = PillowWriter(fps=60)
anim.save('Burger.gif', writer=writer)
