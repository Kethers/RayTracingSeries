# Ray Tracing In One Weekend

My practice code and some note of [**_Ray Tracing in One Weekend_**](https://raytracing.github.io/books/RayTracingInOneWeekend.html) (Version 4.0.0-alpha.1, 2023-08-06)

## Proof of perpendicular part of refracted ray formula

In section _11.2. Snell‘s Law_, there is a formula:

$\mathrm{R}_{\perp}^{\prime}=\frac{\eta}{\eta^{\prime}}(\mathrm{R}+\cos \theta n)$

How to reach this formula? Below lies the proof procedure:

Before starting, we need to realize that the incident ray vector and the refracted ray vector are both unit vectors.

According to the Snell's law:

$\eta \cdot \sin \theta=\eta^{\prime} \cdot \sin \theta^{\prime}$

Unfold the $\sin \theta$ and the $\sin\theta^{\prime}$, yielding:

$\eta \cdot \frac{\|\mathrm{R}_{\perp}\|}{\|\mathrm{R}\|} = \eta^{\prime} \cdot \frac{\|\mathrm{R}_{\perp}^{\prime}\|}{\|\mathrm{R}^{\prime}\|}$

$\because \|\mathrm{R}\|=\|\mathrm{R}^{\prime}\|=unit \space vector$

$\therefore \|\mathrm{R}_{\perp}^{\prime}\|=\frac{\eta}{\eta^{\prime}}\|\mathrm{R}_{\perp}\|$

$\because \mathrm{R}_{\perp}^{\prime}$ and $\mathrm{R}_{\perp}$ are in the same direction

$\therefore \mathrm{R}_{\perp}^{\prime}=\frac{\eta}{\eta^{\prime}}\mathrm{R}_{\perp} \space \cdots \space \cdots (1)$

$\because \|\mathrm{R}_{\parallel}\|=\|\mathrm{R}\| \cdot \cos \theta$ , $\|\mathrm{R}\|=\|\mathrm{n}\|=unit \space vector$

$\therefore \|\mathrm{R}_{\parallel}\|=\|\mathrm{n}\| \cdot \cos \theta$

$\because \mathrm{R}$ and $\mathrm{n}$ are in the opposite direction

$\therefore \mathrm{R}_{\parallel}=-\mathrm{n} \cdot \cos \theta$

$\because \mathrm{R}_{\perp}=\mathrm{R}-\mathrm{R}_{\parallel}$

$\therefore \mathrm{R}_{\perp}=\mathrm{R}+\mathrm{n}\cdot \cos \theta \space \cdots \space \cdots (2)$

Combine the formula (1) and the formula (2), yielding:

$\mathrm{R}_{\perp}^{\prime}=\frac{\eta}{\eta^{\prime}}(\mathrm{R}+\cos \theta n)$

Q.E.D.



## Result

Second time learning (book: Version 4.0.0-alpha.1, 2023-08-06)

It’s been a long time since I finished learning book 1. Recently I decide to learn the remaining 2 books only to find that there’s a version upgrade. So I relearning the book of version 4.0.0 alpha and upgrade my code to this version. Furthermore, I use OpenMP to parallelize the ray cast loop and use native OS environment (Windows 11) to run the code. Now with AMD Ryzen 9 7950X 16-Core Processor it only takes 1~2 minutes to get an image.

-- 2023.11.06

![image_4_0_0_alpha1](./image_4_0_0_alpha1.png)



First time learning (book: Version 3.2.3, 2020-12-07):

The final code in section 13 might take your computer hours to run and get the result image. (I use a Virtual Box VM with 4 CPUs of i7-8750h and it takes about 15 hours to complete)

Manage your time and good luck.

-- 2021.10.30

![image_3_2_3](./image_3_2_3.png)
