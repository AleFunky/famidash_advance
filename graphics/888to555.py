def rgb888_to_rgb555_24bit(rgb888):
    """
    Converts a 24-bit integer (RGB888) to a 16-bit integer (RGB555).
    
    Parameters:
    - rgb888: 24-bit integer representing an RGB888 color.
    
    Returns:
    - 16-bit integer representing an RGB555 color.
    """
    # Extract RGB888 components
    r = (rgb888 >> 16) & 0xFF  # Extract red (highest byte)
    g = (rgb888 >> 8) & 0xFF   # Extract green (middle byte)
    b = rgb888 & 0xFF          # Extract blue (lowest byte)
    
    # Convert to RGB555
    r_5 = (r >> 3) & 0x1F  # 5 bits for red
    g_5 = (g >> 3) & 0x1F  # 5 bits for green
    b_5 = (b >> 3) & 0x1F  # 5 bits for blue
    
    # Combine into a 16-bit BGR555 value
    rgb555 = (b_5 << 10) | (g_5 << 5) | r_5
    
    return rgb555

def convert_list_rgb888_to_rgb555_24bit(rgb888_list):
    """
    Converts a list of 24-bit RGB888 integers to 16-bit RGB555 integers.
    
    Parameters:
    - rgb888_list: List of 24-bit integers representing RGB888 colors.
    
    Returns:
    - List of 16-bit integers representing RGB555 colors.
    """
    return [rgb888_to_rgb555_24bit(rgb888) for rgb888 in rgb888_list]

# Example usage
if __name__ == "__main__":
    # List of RGB888 colors as 24-bit integers
    rgb888_list = [
        0x70F8F8,
        0x38D0F8,
        0x00B0F8,
        0x104858,

        0xF8F840,
        0xF8F048,
        0xF8E050,
        0x585018,

    ]
    
    # Convert the list
    converted_colors = convert_list_rgb888_to_rgb555_24bit(rgb888_list)
    
    # Display results
    for original, converted in zip(rgb888_list, converted_colors):
        print(f"0x{converted:04X}, ", end="")
    print()