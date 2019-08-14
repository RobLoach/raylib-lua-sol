# Get the sources together
set(example_dirs audio core text textures)
set(example_sources)
set(example_resources)

# Examples directories
foreach(example_dir ${example_dirs})
  file(GLOB sources ${example_dir}/*.lua)
  list(APPEND example_sources ${sources})

  # Any all resources.
  file(GLOB resources ${example_dir}/resources/*)
  list(APPEND example_resources ${resources})
endforeach()

# Add all examples.
foreach(example_source ${example_sources})
  # Create the basename for the example
  get_filename_component(example_name ${example_source} NAME)

  configure_file(${example_source} ${example_name} COPYONLY)

  string(REGEX MATCH ".*/.*/" resources_dir ${example_source})
  string(APPEND resources_dir "resources")
endforeach()

# Resources
file(COPY ${example_resources} DESTINATION "resources/")
