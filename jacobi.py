import numpy as np

def jacobi(A, b, x0=None, tol=1e-10, max_iterations=1000):
    n = len(b)
    x = np.zeros(n) if x0 is None else x0
    iterations = 0

    # Check if A is diagonally dominant
    for i in range(n):
        row_sum = sum(abs(A[i, j]) for j in range(n) if j != i)
        if abs(A[i, i]) < row_sum:
            raise ValueError("Matrix A is not diagonally dominant.")
    
    while iterations < max_iterations:
        x_new = np.copy(x)
        for i in range(n):
            sum_ = 0
            for j in range(n):
                if j != i:
                    sum_ += A[i, j] * x[j]
            x_new[i] = (b[i] - sum_) / A[i, i]

        # Check for convergence
        if np.linalg.norm(x_new - x, ord=np.inf) < tol:
            break
        
        x = x_new
        iterations += 1

    return x, iterations

# Example usage
if __name__ == "__main__":
    A = np.array([[4, -1, 0, 0],
                  [-1, 4, -1, 0],
                  [0, -1, 4, -1],
                  [0, 0, -1, 3]], dtype=float)
    
    b = np.array([15, 10, 10, 10], dtype=float)
    x_initial = np.zeros(len(b))

    solution, iters = jacobi(A, b, x0=x_initial)

    print("Solution:", solution)
    print("Iterations:", iters)