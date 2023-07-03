bool skip
  # Skip this configuration and continue.
bool skip_object
  # Skip the current object and continue.

## Tool
string tool_name
  # Tool's cofiguration specifying the TCP and the digital
  # IO to actuate the gripper and to get back its feedback. 

## Object
string object_name
  # Object's configuration specifying the shape of the object
  # (box, cylinder, cone, sphere) and it's size. 
  # Required to compute the picking point.
float64 object_weight
  # The object's weight expressed in [Kg]

## Pattern Manager
string pattern_file
  # The path to the file containing the pattern to load.
string transform_name
  # The transform (aka. layer) to activate before starting the palletizing task.
bool reload_pattern
  # Reload the pattern and reactivate the layer.

int32 start_index
  # Skip first n indexes before start iterating on a new layer. (default: 0)
