import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline

# Data
RL_values = np.array([144.4, 221, 495, 975, 1540])
PL_values = np.array([0.0283024, 0.032824, 0.040095, 0.0351, 0.02464])

# Labels for x-axis
RL_labels = [r"$R_{TH/4}$", r"$R_{TH/2}$", r"$R_{TH}$", r"$2R_{TH}$", r"$3R_{TH}$"]

# Create smooth curve using cubic spline
xnew = np.linspace(RL_values.min(), RL_values.max(), 300)  # dense points
spline = make_interp_spline(RL_values, PL_values, k=3)    # cubic spline
ynew = spline(xnew)

# Plot
plt.figure(figsize=(8,5))   # (width=8, height=5 inches)
plt.plot(xnew, ynew, 'b-', label=r"$P_L \, vs \, R_L$")   # smooth curve
plt.plot(RL_values, PL_values, 'bo')                      # original points
plt.xlabel(r"$R_L \, (\Omega)$")
plt.ylabel(r"$P_L \, (W)$")
plt.legend()
plt.xticks(RL_values, RL_labels)   # custom tick labels
plt.box(True)                      # draw frame around plot
plt.show()
