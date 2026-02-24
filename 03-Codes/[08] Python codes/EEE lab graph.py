import matplotlib.pyplot as plt

# Data
RL_values = [144.4    ,      221 ,    495 ,   975 ,1540 ]
PL_values = [0.0283024, 0.032824, 0.040095, 0.0351, 0.02464]

# Labels for x-axis
RL_labels = [r"$R_{TH/4}$", r"$R_{TH/2}$", r"$R_{TH}$", r"$2R_{TH}$", r"$3R_{TH}$"]

# Plot
plt.figure(figsize=(8,5))
plt.plot(RL_values, PL_values, 'o-b', label=r"$P_L \, vs \, R_L$")
plt.xlabel(r"$R_L \, (\Omega)$")
plt.ylabel(r"$P_L \, (W)$")
plt.legend()

# Custom ticks
plt.xticks(RL_values, RL_labels)

# Add grid and box
plt.grid(False)
plt.box(True)

plt.show()
