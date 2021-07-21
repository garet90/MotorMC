# MotorMC
***Note: MotorMC is currently in development and is not ready for production servers.***
MotorMC is a blazing fast, multi-threaded, asynchronous version of Minecraft that aims to handle many players on a single world while still providing an experience as close to vanilla Minecraft as possible.
## About
Unlike vanilla Minecraft, MotorMC is written in the C programming language--the same programming language your operating system is written in--to get maximum performance by removing the overhead of the Java Runtime Environment. Additionally, MotorMC does not utilize a garbage collector meaning each piece of memory is manually allocated and freed, allowing for extremely low memory usage.
### Multi-threading
In vanilla Minecraft, everything resource-intensive runs on a single thread. But, as newer processors have upwards of 8, 16, and even 32 cores, this leaves the processor mainly unutilized. MotorMC seeks to remedy this by splitting up all the work, such as block updates and entity calculations, between all of the cores. Other third-party Minecraft implementations have attempted this in the past, usually by splitting the world into pieces and assigning each piece to a different thread, but this can be grossly inefficient at times. By using a job pooling and main thread managing worker threads model, jobs can be more efficiently distributed to run every task in parallel.
### Plugin API
MotorMC is designed with plugin compatibility in mind. There already exists a very experimental API that allows for the same drag-and-drop plugin experience found on software like Spigot and Paper. A wiki outlining the API and its use will be made eventually.
## Downloading
Currently, this project utilizes GitHub Actions to build binaries. These binaries should work out-of-the-box with Windows, Linux, and even MacOS. To download a binary, navigate to the "Actions" tab, click on the most recent successful build, and download the binary that is compatible with your system.
### GCC vs Clang
Binaries for Windows and Ubuntu are built with two different compilers: GCC and Clang. Server hosts should test each binary to see which one works better for their individual system but both should be compatible.