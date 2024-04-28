import numpy as np

N = 1_000_000


def pdist(a, b):
    r1, t1 = a
    r2, t2 = b

    return np.sqrt(r1**2 + r2**2 - 2 * r1 * r2 * np.cos(t1 - t2))

### ### ### ### ###


m = 0.5
mt = np.pi

d_m_flag = 0
d_rnd_flag = 0

d_t_fx_flag = 0
d_t_rnd_flag = 0

A = 0

for _ in range(N):
    flag_r = np.random.uniform(0, 1)
    d_m_flag += np.linalg.norm(flag_r-m)
    d_rnd_flag += np.linalg.norm(flag_r-np.random.uniform(0, 1))

    flag_t = np.random.uniform(0, 2*np.pi)
    d_t_fx_flag += pdist((flag_r, flag_t), (flag_r, mt))
    d_t_rnd_flag += pdist(
        (flag_r, flag_t),
        (flag_r, np.random.uniform(0, 2*np.pi))
    )

    if np.linalg.norm(flag_r-m) > pdist((flag_r, flag_t), (flag_r, mt)):
        A += 1

d_m_flag /= N
d_rnd_flag /= N

print(f"d_m_flag = {d_m_flag}")
print(f"d_rnd_flag = {d_rnd_flag}")

d_t_fx_flag /= N
d_t_rnd_flag /= N

print(f"d_t_fx_flag = {d_t_fx_flag}")
print(f"d_t_rnd_flag = {d_t_rnd_flag}")

print(f"A = {A / N}")

### ### ### ### ###
