
require 'yaml'

puts YAML.parse_file('strlen/checklist.yml').to_a.to_s
