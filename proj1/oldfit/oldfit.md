
Unfortunately we *can't* mesure the diode junction voltage directly, becuse the diode body itself has resistance and this in-line resistance is built in to the diode! ;-( We can correct for this however by including an internal resistance term in the model. Let's work that out. If you add a term for the internal resistance ($r$) of the diode itself:

$$ V_{ext} = V_d + Ir = A \ln(I) + B + Ir $$

Note that $r$, the internal resistance, is multiplied by $I$ to determine the size of the additional voltage drop across the diode. Note that this is equivalent to:

$$ V_{ext} = A \ln(I) + B + I C $$

where $C$ is just the internal resistance

$$C = r$$

This changes our mode to a slightly more complicated (and non-linear) function:

    def internal_R_model(I, A, B, C):
        return A*np.log(I) + C*I + B

The good news is that `curve_fit` doesn't care if the function is linear or not! Use this function, and the data you collected, to estimate values of these three parameters along with their estimated uncertainty. Once you have $A$, $B$ and $C$ you can work backwards to find $I_o$ and $\eta$ as well.


