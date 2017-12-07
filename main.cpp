#include <gst/gst.h>
#include <string>
#include <iostream>
#include <cstdlib>

int main (int argc, char *argv[])
{
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;
  GError *error = NULL;

  gst_init (&argc, &argv);

  std::string host = "10.0.0.26";
  std::string port = "5000";
  // for (int x=0;x < argc; x++) {
  //   std::cout << x << " : " << argv[x] << std::endl;
  // }

  if (argc > 1) {
    host = argv[1];
  }
  if (argc > 2) {
    port = argv[2];
  }
    /* Build the pipeline */
    std::string pipeString = "v4l2src device=/dev/video0 ! "
          "video/x-raw, format=(string)I420, width=640,height=480, framerate=40/1 ! "
          "nvvidconv ! "
          "video/x-raw(memory:NVMM), format=(string)I420 ! "
          "omxh264enc low-latency=true ! "
          "rtph264pay config-interval=3 ! "
          "udpsink sync=false host=" + host + " port=" + port;
    pipeline = gst_parse_launch (pipeString.c_str(), &error);
    if (!pipeline) {
      g_print ("Parse error: %s\n", error->message);
      exit (1);
    }

    /* Start playing */
    gst_element_set_state (pipeline, GST_STATE_PLAYING);

    /* Wait until error or EOS */
    bus = gst_element_get_bus (pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_EOS);

    /* Free resources */
    if (msg != NULL)
      gst_message_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    return 0;
  }
