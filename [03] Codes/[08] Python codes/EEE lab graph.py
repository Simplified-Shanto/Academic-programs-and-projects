import matplotlib.pyplot as plt

# Theoretical (ideal) relationship: V_L = 10 * I_L
I_L_ideal = [0, 0.5, 1, 1.5, 2]
V_L_ideal = [10 * i for i in I_L_ideal]

# Create the plot
plt.figure(figsize=(6, 4))
plt.plot(I_L_ideal, V_L_ideal, '-k', label='Ideal Linear Relationship')  # black straight line

# Labels and title
plt.xlabel('Load Current $I_L$ (A)', fontsize=12)
plt.ylabel('Load Voltage $V_L$ (V)', fontsize=12)
plt.title('Theoretical Load Voltage vs Load Current', fontsize=14)
plt.grid(True, linestyle='--', linewidth=0.5, color='gray')
plt.legend()

# Fix axes range for consistency with previous graph
plt.xlim(0, 2)
plt.ylim(0, 20)

# Show the plot
plt.tight_layout()
plt.show()
