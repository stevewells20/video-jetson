# ScubaVision (Jetson side)

This is video streaming development code for the Oregon Statue University Robotics Club (OSURC) entry ROV for the 2018 MATE ROV competetition.  It is not yet in a distributable state, and will likely not be until after the competition.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```

Host computer: (which will receive the video)

	* OpenCV 3.3.1 (and its deps)
		-> Must be compiled with Gstreamer v(1.0|0.1) turned on


Jetson TK1: (which will send the video)

	* Gstreamer-1.0 (can work with v-0.1 with some adjustments)
	* Camera (tested on PS Eye)
	* Jetpack 21.5 (R21, Rev5.0)
	* Grinch Kernel

```

### Installing

A step by step series of examples that tell you have to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [OpenCV](http://www.opencv.org)

## Contributing

Please read [CONTRIBUTING.md]()

## Versioning


## Authors

* **Steven Wells** - *Evil Lackey* 
* **Jeramie Chew** - *Computer Scientist*

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Thanks to the large number of informative posts on the Nvidia forums, without which we would
	still be trying to figure out why ffmpeg doesn't work.
 
