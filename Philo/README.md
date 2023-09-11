# Philosophers 

## Description

This project simulates the classic dining philosophers problem using both threads and processes, as specified in the assignment guidelines.

## Table of Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)

## Requirements

To run this project, you need:

- A C compiler (e.g., GCC)
- Pthreads library (for `philo`)
- Semaphore library (for `philo_bonus`)

## Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/philosophers.git
```

Compile the project:

```bash
cd philo/          # for philo
make
```

or

```bash
cd philo_bonus/    # for philo_bonus
make
```

## Usage

To run the project, use the following command:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]
```

- `number_of_philosophers`: Number of philosophers and forks.
- `time_to_die`: Time in milliseconds until a philosopher dies without eating.
- `time_to_eat`: Time in milliseconds that a philosopher takes to eat.
- `time_to_sleep`: Time in milliseconds that a philosopher takes to sleep.
- `number_of_times_each_philosopher_must_eat` (optional): Number of times each philosopher must eat before the simulation ends.

## Examples

```bash
./philo 5 800 200 200
```

This command will run the simulation with 5 philosophers, a time limit of 800 ms for a philosopher to die, 200 ms for eating, and 200 ms for sleeping.

## Contributing

Contributions are welcome! If you want to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bugfix: `git checkout -b feature-name`.
3. Commit your changes: `git commit -m "Description of your changes"`.
4. Push your branch: `git push origin feature-name`.
5. Open a pull request on the main repository.