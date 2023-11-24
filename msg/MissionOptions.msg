bool skip
  # If true, skip this configuration and continue

string mission_type
  # Possibilities are: ['StoreToBuffer', 'StoreToPallet', 'BufferToPallet']
string object_type
  # Possibilities are: ['small_box', 'large_box']

geometry_msgs/PoseStamped object_pose
  # The object's pose to pickup
geometry_msgs/PoseStamped location_pose
  # The location's pose for place