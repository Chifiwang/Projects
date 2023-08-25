import numpy as np

# Starting Conditions
#Start pos
x_0 = 0
y_0 = 1

#Constants
v = 1
r = 1
w = 1
d = 1

# Euler's Method Parameters
T_END = 10
dt = 0.01
num_iterations = (int) (np.round(T_END/dt))


# Reference Frames
# Equation (6) in code
class static_axis: 
    def dxdt(x, y, t):
        return (v*(r*np.cos(w*t)-x)/np.sqrt(np.square(r*np.cos(w*t)-x) 
                + np.square(r*np.sin(w*t)-y)))
    def dydt(x, y, t):
        return (v*(r*np.sin(w*t)-y)/np.sqrt(np.square(r*np.cos(w*t)-x) 
                + np.square(r*np.sin(w*t)-y)))

# Equation (9) in code
class rotating_axis:
    def dxdt(x, y, t):
        return (v*(r-x)/np.sqrt(np.square(r-x)+np.square(y)) -w*y)
    def dydt(x, y, t):
        return (v*(-y)/np.sqrt(np.square(r-x)+np.square(y)) +w*x)

# Euler's Method was adapted from Hugo de Groot's implemetation
# Euler's Method:
def eulers_method(reference_frame):
    x_n = np.zeros(num_iterations+1)
    y_n = np.zeros(num_iterations+1)
    t_n = np.zeros(num_iterations+1)
    x_n[0] = d*x_0
    y_n[0] = d*y_0

    for i in range(1, num_iterations + 1):
        x = x_n[i-1]
        y = y_n[i-1]
        t = t_n[i-1]

        dx = reference_frame.dxdt(x, y, t)
        dy = reference_frame.dydt(x, y, t)

        x_n[i] = x + dx*dt
        y_n[i] = y + dy*dt
        t_n[i] = t + dt

    for i in range(0, num_iterations + 1):
        print(x_n[i], y_n[i], t_n[i])

# Uncomment to use
#eulers_method(static_axis)
eulers_method(tractrix)